
#include "spritebatch.hpp"
#include "bgfx_utils.h"

namespace bgfx
{
	struct PosColorTexCoord0Vertex
	{
		float m_position[3];
		uint32_t m_abgr;
		float m_uv[2];

		static bgfx::VertexLayout Init()
		{
			bgfx::VertexLayout layout;
			layout.begin()
				.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
				.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
				.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
				.end();
			return layout;
		}

		static bgfx::VertexLayout Layout;
	};

	bgfx::VertexLayout PosColorTexCoord0Vertex::Layout = PosColorTexCoord0Vertex::Init();

	void SpriteBatch::create()
	{
		m_sampler = bgfx::createUniform("s_tex", bgfx::UniformType::Sampler);
		m_transformMatrix = bgfx::createUniform("u_matrixTransform", bgfx::UniformType::Mat4);
		m_spriteProgram = loadProgram("vs_spritebatch", "fs_spritebatch");
	}

	void SpriteBatch::destroy()
	{

	}

	void SpriteBatch::begin(
		SpriteSortMode::Enum sortMode
		, SpriteBlendMode::Enum blendMode
		, const void* matrix
		, FrameBufferHandle renderTarget)
	{
		(void)sortMode;
		(void)blendMode;
		(void)matrix;
		(void)renderTarget;
	}

	void SpriteBatch::draw(
		Sprite sprite
		, const bx::Vec3& position
		, uint32_t abgr)
	{
		(void)sprite;
		(void)position;
		(void)abgr;
	}

	void SpriteBatch::end()
	{

	}

	void SpriteBatch::draw(Sprite texture, float destination[4], float sourceRectangle[4], uint32_t color, float originRotationDepth[4], uint32_t flags, int sortLayer)
	{
		(void)texture;
		(void)destination;
		(void)sourceRectangle;
		(void)color;
		(void)originRotationDepth;
		(void)flags;
		(void)sortLayer;
	}

	void SpriteBatch::prepareForRendering()
	{

	}

	void SpriteBatch::growSpriteQueue()
	{

	}

	void SpriteBatch::growSortedSprites()
	{

	}

	void SpriteBatch::renderSprite(SpriteInfo* sprite, void* vertices, float textureSize[2], float inverseTextureSize[2])
	{
		(void)sprite;
		(void)vertices;
		(void)textureSize;
		(void)inverseTextureSize;
	}

	void SpriteBatch::renderBatch(Sprite texture, SpriteInfo* spriteInfo, uint32_t batchSize)
	{
		(void)texture;
		(void)spriteInfo;
		(void)batchSize;
	}

	void SpriteBatch::flushBatch()
	{

	}

	void SpriteBatch::sortSprites()
	{

	}
}
