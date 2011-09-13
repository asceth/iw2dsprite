#include "prereqs.h"
#include "sprite_sheet.h"
#include "sprite.h"

IW_MANAGED_IMPLEMENT(Sprite);

bool Sprite::ParseAttribute(CIwTextParserITX* pParser, const char* pAttrName)
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

void Sprite::ParseClose(CIwTextParserITX* pParser)
{
  sheet = (SpriteSheet*)IwGetTextParserITX()->GetObject(-1);

  sheet->sprites.push_back(this);
}

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
  IW_ARRAY_ITERATE_INT(vn, animations)
    {
      delete animations[vn];
    }
}

SpriteAnimation* Sprite::animation(const char* name)
{
  IW_ARRAY_ITERATE_INT(vn, animations)
    {
      if (!strcmp(animations[vn]->name.c_str(), name))
        {
          return animations[vn];
        }
    }
  return NULL;
}

IW_CLASS_FACTORY(Sprite);
