
#ifndef BGFX_SPRITEBATCH_H_HEADER_GUARD
#define BGFX_SPRITEBATCH_H_HEADER_GUARD

#include <bgfx/bgfx.h>
#include <bx/math.h>
#include <tinystl/allocator.h>
#include <tinystl/vector.h>

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
		TextureHandle m_texture;
		uint16_t m_width;
		uint16_t m_height;
	};

	struct SpriteBatch
	{
		void create();

		void destroy();

		void begin(
			SpriteSortMode::Enum sortMode = SpriteSortMode::Deferred
			, SpriteBlendMode::Enum blendMode = SpriteBlendMode::AlphaBlend
			, const void* matrix = nullptr
			, FrameBufferHandle renderTarget = { kInvalidHandle });

		void draw(
			Sprite sprite
			, const bx::Vec3& position
			, uint32_t abgr = UINT32_MAX);

		void end();

	private:

		struct SpriteInfo
		{
			Sprite m_texture;
			float m_source[4];
			float m_destination[4];
			int m_sortLayer;
			float m_originRotationDepth[4];
			uint32_t m_color;
			uint32_t m_flags;
		};

		UniformHandle m_sampler;
		UniformHandle m_transformMatrix;
		ProgramHandle m_spriteProgram;
		FrameBufferHandle m_frameBufferHandle;

		SpriteSortMode::Enum m_sortMode;
		SpriteBlendMode::Enum m_blendMode;
		float m_matrix[16];

		bool m_beginCalled;
		uint32_t m_spriteQueueCount;
		uint32_t m_spriteQueueArraySize;

		tinystl::vector<SpriteInfo*> m_spritesSorted;
		tinystl::vector<SpriteInfo> m_sprites;

		void draw(Sprite texture, float destination[4], float sourceRectangle[4], uint32_t color, float originRotationDepth[4], uint32_t flags, int sortLayer = 0);
		void prepareForRendering();
		void growSpriteQueue();
		void growSortedSprites();
		void renderSprite(SpriteInfo* sprite, void* vertices, float textureSize[2], float inverseTextureSize[2]);
		void renderBatch(Sprite texture, SpriteInfo* spriteInfo, uint32_t batchSize);
		void flushBatch();
		void sortSprites();
	};
}

#endif
