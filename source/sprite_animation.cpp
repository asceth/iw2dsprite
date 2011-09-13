#include "prereqs.h"
#include "sprite_sheet.h"
#include "sprite.h"
#include "sprite_animation.h"

IW_MANAGED_IMPLEMENT(SpriteAnimation);

bool SpriteAnimation::ParseAttribute(CIwTextParserITX* pParser, const char* pAttrName)
{
  char line[32];
  if (!strcmp(pAttrName, "name"))
    {
      pParser->ReadString(line, 32);
      name = line;
    }
  else
    {
      return CIwManaged::ParseAttribute(pParser, pAttrName);
    }

  return true;
}

void SpriteAnimation::ParseClose(CIwTextParserITX* pParser)
{
  sprite = (Sprite*)IwGetTextParserITX()->GetObject(-1);

  sprite->animations.push_back(this);
}

SpriteAnimation::SpriteAnimation()
{
}

SpriteAnimation::~SpriteAnimation()
{
  IW_ARRAY_ITERATE_INT(vn, frames)
    {
      delete frames[vn];
    }
}

SpriteFrame* SpriteAnimation::frame(const char* name)
{
  IW_ARRAY_ITERATE_INT(vn, frames)
    {
      if (!strcmp(frames[vn]->name.c_str(), name))
        {
          return frames[vn];
        }
    }
  return NULL;
}

IW_CLASS_FACTORY(SpriteAnimation);
