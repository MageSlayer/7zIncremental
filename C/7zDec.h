/* 7zDec.h -- Unpack functions
2013-04-15 : Denis Golovan : Public domain */

#ifndef __7Z_DEC_H
#define __7Z_DEC_H

#include "7z.h"
#include "7zAlloc.h"
#include "LzmaDec.h"

typedef struct
{
  CLzmaDec state;
  CSzCoderInfo *coder;
  ILookInStream *inStream;

  SRes lastRes;			// last operation result.
  Byte *outBuffer;		// User-specified unpack buffer.
  Byte *outBufferCur;		// Current unpack buffer position (always within [outBuffer; outBuffer + outSize - 1]).
  SizeT outSize;		// User-specified unpack buffer size.

  Byte *inBuffer;               // Moves to the end of inStream buffer (inBufferEnd) while blocks are unpacked.
                                // No need to free it as points into inStream buffer.
  Byte *inBufferEnd;

  SizeT inSize;	                // total packed file size.
  SizeT inSizeLeft;             // how much data left to unpack.

  ISzAlloc *allocMain;
} SzLzmaDecoderState;

SRes SzFolder_Decode_Block(const CSzFolder *folder, const UInt64 *packSizes,
			   ILookInStream *inStream, UInt64 startPos,
			   Byte *outBuffer, SizeT outSize, ISzAlloc *allocMain,
			   SzLzmaDecoderState **state
			   );
SRes SzLzmaDecoderState_Free(SzLzmaDecoderState *state);
SRes SzLzmaDecoderState_UnpackBlock(SzLzmaDecoderState *state, SizeT *BlockRead);

#endif
