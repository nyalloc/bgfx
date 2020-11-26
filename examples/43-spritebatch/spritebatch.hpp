
#ifndef BGFX_SPRITEBATCH_H_HEADER_GUARD
#define BGFX_SPRITEBATCH_H_HEADER_GUARD

#include <bgfx/bgfx.h>
#include <bx/math.h>

/// BGFX
namespace bgfx
{
	struct SpriteSortMode
	{
		enum Enum
		{
			Deferred,
			Immediate,
			Texture,
			BackToFront,
			FrontToBack,
			Count
		};
	};

	struct SpriteBlendMode
	{
		enum Enum
		{
			None,
			AlphaBlend,
			Additive,
			PreMultiplied,
			Count
		};
	};

	struct SpriteEffects
	{
		enum Enum
		{
			None,
			FlipHorizontally,
			FlipVertically,
			FlipBoth,
			Count
		};
	};

	struct Sprite
	{
		TextureHandle texture;
		uint32_t width;
		uint32_t height;
	};

	struct SpriteBatch
	{
		SpriteBatch()
		{

		}

		void Begin(
			uint16_t viewID = 0
			, SpriteSortMode::Enum sortMode = SpriteSortMode::Deferred
			, SpriteBlendMode::Enum blendMode = SpriteBlendMode::AlphaBlend
			, const float* matrix = nullptr
			, FrameBufferHandle renderTarget = { kInvalidHandle })
		{
			(void)viewID;
			(void)sortMode;
			(void)blendMode;
			(void)matrix;
			(void)renderTarget;
		}

		void Draw(
			Sprite sprite
			, const bx::Vec3& position
			, uint32_t abgr = UINT32_MAX)
		{
			(void)sprite;
			(void)position;
			(void)abgr;
		}

		void End()
		{

		}

	private:

	};
}

#endif
