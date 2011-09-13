#ifndef __SPRITE_FRAME_H__
#define __SPRITE_FRAME_H__

class SpriteFrame : public CIwManaged
{
public:
  IW_MANAGED_DECLARE(SpriteFrame);

  virtual bool ParseAttribute(CIwTextParserITX *pParser, const char* pAttrName);
  virtual void ParseClose(CIwTextParserITX *pParser);

  SpriteAnimation* animation;
  CIwString<32> name;
  int32 speed;
  int32 position;
  int32 width;
  int32 height;
  int32 area;
  int32 x;
  int32 y;


  CIwSVec2 region_offset()
  {
    return CIwSVec2(x, y);
  }

  CIwSVec2 region_size()
  {
    return CIwSVec2(width, height);
  }

  SpriteFrame();
  ~SpriteFrame();
};

#endif
