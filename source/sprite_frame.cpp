#include "prereqs.h"
#include "sprite_sheet.h"
#include "sprite.h"
#include "sprite_animation.h"
#include "sprite_frame.h"

IW_MANAGED_IMPLEMENT(SpriteFrame);

bool SpriteFrame::ParseAttribute(CIwTextParserITX* pParser, const char* pAttrName)
{
  char line[0x100];
  int32 parsed_value;
  if (!strcmp(pAttrName, "name"))
    {
      pParser->ReadString(line, 0x100);
      name = line;
    }
  else if (!strcmp(pAttrName, "speed"))
    {
      pParser->ReadInt32(&parsed_value);
      speed = parsed_value;
    }
  else if (!strcmp(pAttrName, "position"))
    {
      pParser->ReadInt32(&parsed_value);
      position = parsed_value;
    }
  else if (!strcmp(pAttrName, "width"))
    {
      pParser->ReadInt32(&parsed_value);
      width = parsed_value;
    }
  else if (!strcmp(pAttrName, "height"))
    {
      pParser->ReadInt32(&parsed_value);
      height = parsed_value;
    }
  else if (!strcmp(pAttrName, "area"))
    {
      pParser->ReadInt32(&parsed_value);
      area = parsed_value;
    }
  else if (!strcmp(pAttrName, "x"))
    {
      pParser->ReadInt32(&parsed_value);
      x = parsed_value;
    }
  else if (!strcmp(pAttrName, "y"))
    {
      pParser->ReadInt32(&parsed_value);
      y = parsed_value;
    }
  else
    {
      return CIwManaged::ParseAttribute(pParser, pAttrName);
    }

  return true;
}

void SpriteFrame::ParseClose(CIwTextParserITX* pParser)
{
  animation = (SpriteAnimation*)IwGetTextParserITX()->GetObject(-1);

  animation->frames.push_back(this);
}

SpriteFrame::SpriteFrame()
{
}

SpriteFrame::~SpriteFrame()
{
}

IW_CLASS_FACTORY(SpriteFrame);
