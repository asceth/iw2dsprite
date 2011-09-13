#ifndef __SPRITE_H__
#define __SPRITE_H__

class Sprite : public CIwManaged
{
public:
  IW_MANAGED_DECLARE(Sprite);

	virtual bool ParseAttribute(CIwTextParserITX *pParser, const char *pAttrName);
  virtual void ParseClose(CIwTextParserITX* pParser);

  SpriteSheet* sheet;
  CIwString<32> name;
  CIwArray<SpriteAnimation*> animations;

  Sprite();
  ~Sprite();

  SpriteAnimation* animation(const char* name);
};

#endif
