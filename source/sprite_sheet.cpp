#include "prereqs.h"
#include "sprite_sheet.h"

IW_MANAGED_IMPLEMENT(SpriteSheet);

bool SpriteSheet::ParseAttribute(CIwTextParserITX* pParser, const char* pAttrName)
{
  char line[0x100];
  if (!strcmp(pAttrName, "name"))
    {
      pParser->ReadString(line, 0x100);
      name = line;

      image = Iw2DCreateImageResource(name.c_str());
    }
  else
    {
      return CIwManaged::ParseAttribute(pParser, pAttrName);
    }

  return true;
}

void SpriteSheet::ParseClose(CIwTextParserITX* pParser)
{
  database.sprite_sheets.push_back(this);
}

SpriteSheet::SpriteSheet()
{
  image = NULL;
}

SpriteSheet::~SpriteSheet()
{
  if (image)
    {
      delete image;
    }

  IW_ARRAY_ITERATE_INT(vn, sprites)
    {
      delete sprites[vn];
    }
}

Sprite* SpriteSheet::sprite(const char* name)
{
  IW_ARRAY_ITERATE_INT(vn, sprites)
    {
      if (!strcmp(sprites[vn]->name.c_str(), name))
        {
          return sprites[vn];
        }
    }
  return NULL;
}

IW_CLASS_FACTORY(SpriteSheet);
