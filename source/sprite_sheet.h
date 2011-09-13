#ifndef _SPRITESHEET_H_
#define _SPRITESHEET_H_

class SpriteSheet : public CIwManaged
{
public:
  IW_MANAGED_DECLARE(SpriteSheet);

  virtual bool ParseAttribute(CIwTextParserITX *pParser, const char* pAttrName);
  virtual void ParseClose(CIwTextParserITX *pParser);

  CIw2DImage* image;
  CIwString<32> name;
  CIwArray<Sprite*> sprites;

  Sprite* sprite(const char* name);
  SpriteSheet();
  ~SpriteSheet();
};

#endif
