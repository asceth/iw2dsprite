#ifndef __SPRITE_ANIMATION_H__
#define __SPRITE_ANIMATION_H__

class SpriteAnimation : public CIwManaged
{
public:
  IW_MANAGED_DECLARE(SpriteAnimation);

  virtual bool ParseAttribute(CIwTextParserITX *pParser, const char *pAttrName);
  virtual void ParseClose(CIwTextParserITX *pParser);

  Sprite* sprite;
  CIwString<32> name;
  CIwArray<SpriteFrame*> frames;

  SpriteAnimation();
  ~SpriteAnimation();

  SpriteFrame* frame(const char* name);
};

#endif
