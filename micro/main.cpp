#include "test_compiler.hpp"
#include "test_draw_arrays.hpp"
#include "test_draw_elements.hpp"
#include "test_draw_arrays_vao.hpp"
#include "test_draw_indexing.hpp"
#include "test_screenspace_coherence.hpp"

std::size_t const TEST_DUPLICATE_COUNT(1);

int drawArrays(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			testDrawArrays::drawType const & DrawType,
			testDrawArrays::vertexDataType const & VertexDataType,
			testDrawArrays::uniformUpdate const & UniformUpdate,
			std::size_t const & DrawCount
		) :
			String(String),
			DrawType(DrawType),
			VertexDataType(VertexDataType),
			UniformUpdate(UniformUpdate),
			DrawCount(DrawCount)
		{}

		std::string const String;
		testDrawArrays::drawType const DrawType;
		testDrawArrays::vertexDataType const VertexDataType;
		testDrawArrays::uniformUpdate const UniformUpdate;
		std::size_t const DrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;
	Entries.push_back(entry("DrawArrays(PACKED, SEPARATED)", testDrawArrays::DRAW_PACKED, testDrawArrays::SEPARATED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(PACKED, SHARED)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(PARAMS, SEPARATED)", testDrawArrays::DRAW_PARAMS, testDrawArrays::SEPARATED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(PARAMS, SHARED)", testDrawArrays::DRAW_PARAMS, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(MULTI, SEPARATED)", testDrawArrays::MULTI_DRAW, testDrawArrays::SEPARATED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(MULTI, SHARED)", testDrawArrays::MULTI_DRAW, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(DISCARD, SEPARATED)", testDrawArrays::MULTI_DISCARD, testDrawArrays::SEPARATED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(DISCARD, SHARED)", testDrawArrays::MULTI_DISCARD, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(INSTANCED, SHARED)", testDrawArrays::INSTANCED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));

	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testDrawArrays Test(argc, argv, test::CORE, 
			Entries[EntryIndex].DrawType, Entries[EntryIndex].VertexDataType, Entries[EntryIndex].UniformUpdate, Entries[EntryIndex].DrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int drawElements(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			testDrawElements::drawType const & DrawType,
			testDrawElements::vertexDataType const & VertexDataType,
			std::size_t const & DrawCount
		) :
			String(String),
			DrawType(DrawType),
			VertexDataType(VertexDataType),
			DrawCount(DrawCount)
		{}

		std::string const String;
		testDrawElements::drawType const DrawType;
		testDrawElements::vertexDataType const VertexDataType;
		std::size_t const DrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;
	Entries.push_back(entry("DrawElements(PACKED, SEPARATED)", testDrawElements::DRAW_PACKED, testDrawElements::SEPARATED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(PACKED, SHARED)", testDrawElements::DRAW_PACKED, testDrawElements::SHARED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(PARAMS, SEPARATED)", testDrawElements::DRAW_PARAMS, testDrawElements::SEPARATED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(PARAMS, SHARED)", testDrawElements::DRAW_PARAMS, testDrawElements::SHARED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(MULTI, SEPARATED)", testDrawElements::MULTI_DRAW, testDrawElements::SEPARATED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(MULTI, SHARED)", testDrawElements::MULTI_DRAW, testDrawElements::SHARED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(DISCARD, SEPARATED)", testDrawElements::MULTI_DISCARD, testDrawElements::SEPARATED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(DISCARD, SHARED)", testDrawElements::MULTI_DISCARD, testDrawElements::SHARED_VERTEX_DATA, 100000));
	Entries.push_back(entry("DrawElements(INSTANCED, SHARED)", testDrawElements::INSTANCED, testDrawElements::SHARED_VERTEX_DATA, 100000));

	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testDrawElements Test(argc, argv, test::CORE, 
			Entries[EntryIndex].DrawType, Entries[EntryIndex].VertexDataType, Entries[EntryIndex].DrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int drawArraysUniform(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			testDrawArrays::drawType const & DrawType,
			testDrawArrays::vertexDataType const & VertexDataType,
			testDrawArrays::uniformUpdate const & UniformUpdate,
			std::size_t const & DrawCount
		) :
			String(String),
			DrawType(DrawType),
			VertexDataType(VertexDataType),
			UniformUpdate(UniformUpdate),
			DrawCount(DrawCount)
		{}

		std::string const String;
		testDrawArrays::drawType const DrawType;
		testDrawArrays::vertexDataType const VertexDataType;
		testDrawArrays::uniformUpdate const UniformUpdate;
		std::size_t const DrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;
	Entries.push_back(entry("MultiDrawArrays(NO_UNIFORM)", testDrawArrays::MULTI_DRAW, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::NO_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(NO_UNIFORM)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::NO_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(CONSTANT_UNIFORM)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::CONSTANT_UNIFORM, 100000));
	Entries.push_back(entry("DrawArrays(PER_DRAW_UNIFORM)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::PER_DRAW_UNIFORM_B2E, 100000));
	Entries.push_back(entry("DrawArrays(REDUNDANT_UNIFORM)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::REDUNDANT_UNIFORM_B2E, 100000));
	Entries.push_back(entry("DrawArrays(PER_DRAW_UNIFORM2)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::PER_DRAW_UNIFORM2_B2E, 100000));
	Entries.push_back(entry("DrawArrays(REDUNDANT_UNIFORM2)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::REDUNDANT_UNIFORM2_B2E, 100000));

	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testDrawArrays Test(argc, argv, test::CORE, 
			Entries[EntryIndex].DrawType, Entries[EntryIndex].VertexDataType, Entries[EntryIndex].UniformUpdate, Entries[EntryIndex].DrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int drawArraysDSA(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			testDrawArrays::drawType const & DrawType,
			testDrawArrays::vertexDataType const & VertexDataType,
			testDrawArrays::uniformUpdate const & UniformUpdate,
			std::size_t const & DrawCount
		) :
			String(String),
			DrawType(DrawType),
			VertexDataType(VertexDataType),
			UniformUpdate(UniformUpdate),
			DrawCount(DrawCount)
		{}

		std::string const String;
		testDrawArrays::drawType const DrawType;
		testDrawArrays::vertexDataType const VertexDataType;
		testDrawArrays::uniformUpdate const UniformUpdate;
		std::size_t const DrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;
	Entries.push_back(entry("DrawArrays(PER_DRAW_UNIFORM_B2E)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::PER_DRAW_UNIFORM_B2E, 100000));
	Entries.push_back(entry("DrawArrays(PER_DRAW_UNIFORM_DSA)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::PER_DRAW_UNIFORM_DSA, 100000));
	Entries.push_back(entry("DrawArrays(REDUNDANT_UNIFORM_B2E)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::REDUNDANT_UNIFORM_B2E, 100000));
	Entries.push_back(entry("DrawArrays(REDUNDANT_UNIFORM_DSA)", testDrawArrays::DRAW_PACKED, testDrawArrays::SHARED_VERTEX_DATA, testDrawArrays::REDUNDANT_UNIFORM_DSA, 100000));

	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testDrawArrays Test(argc, argv, test::CORE, 
			Entries[EntryIndex].DrawType, Entries[EntryIndex].VertexDataType, Entries[EntryIndex].UniformUpdate, Entries[EntryIndex].DrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int drawArraysVAOs(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			testDrawArraysVAO::drawType const & DrawType,
			testDrawArraysVAO::vaoMode const & VAOMode,
			std::size_t const & DrawCount
		) :
			String(String),
			DrawType(DrawType),
			VAOMode(VAOMode),
			DrawCount(DrawCount)
		{}

		std::string const String;
		testDrawArraysVAO::drawType const DrawType;
		testDrawArraysVAO::vaoMode const VAOMode;
		std::size_t const DrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;
	Entries.push_back(entry("MultiDrawArrays(UNIQUE_VAO)", testDrawArraysVAO::MULTI_DRAW, testDrawArraysVAO::UNIQUE_VAO, 100000));
	Entries.push_back(entry("DrawArrays(UNIQUE_VAO)", testDrawArraysVAO::DRAW_PARAMS, testDrawArraysVAO::UNIQUE_VAO, 100000));
	Entries.push_back(entry("DrawArrays(VAOS_UNIQUE_BUFFER)", testDrawArraysVAO::DRAW_PARAMS, testDrawArraysVAO::VAOS_UNIQUE_BUFFER, 100000));
	Entries.push_back(entry("DrawArrays(VAOS_SEPARATED_BUFFERS)", testDrawArraysVAO::DRAW_PARAMS, testDrawArraysVAO::VAOS_SEPARATED_BUFFER, 100000));
	Entries.push_back(entry("DrawArrays(VABS_UNIQUE_BUFFER)", testDrawArraysVAO::DRAW_PARAMS, testDrawArraysVAO::VAOS_UNIQUE_BUFFER, 100000));
	Entries.push_back(entry("DrawArrays(VABS_SEPARATED_BUFFERS)", testDrawArraysVAO::DRAW_PARAMS, testDrawArraysVAO::VABS_SEPARATED_BUFFER, 100000));

	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testDrawArraysVAO Test(argc, argv, test::CORE, 
			Entries[EntryIndex].DrawType, Entries[EntryIndex].VAOMode, Entries[EntryIndex].DrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int drawScreenspaceCoherence(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			glm::uvec2 const & WindowSize,
			glm::uvec2 const & TileSize,
			std::size_t const ViewportDrawCount,
			std::size_t const TileDrawCount
		) :
			String(String),
			WindowSize(WindowSize),
			TileSize(TileSize),
			ViewportDrawCount(ViewportDrawCount),
			TileDrawCount(TileDrawCount)
		{}

		std::string const String;
		glm::uvec2 const WindowSize;
		glm::uvec2 const TileSize;
		std::size_t const ViewportDrawCount;
		std::size_t const TileDrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;

	Entries.push_back(entry("Forward(1024x1024 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 1, 100));
	Entries.push_back(entry("Forward(512x512 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 1, 100));
	Entries.push_back(entry("Forward(256x256 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 1, 100));
	Entries.push_back(entry("Forward(128x128 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 1, 100));
	Entries.push_back(entry("Forward(64x64 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 1, 100));
	Entries.push_back(entry("Forward(32x32 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 1, 100));
	Entries.push_back(entry("Forward(16x16 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 1, 100));
	Entries.push_back(entry("Forward(8x8 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 1, 100));
	Entries.push_back(entry("Forward(512x64 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 64), 1, 100));
	Entries.push_back(entry("Forward(512x32 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 32), 1, 100));
	Entries.push_back(entry("Forward(256x64 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 64), 1, 100));
	Entries.push_back(entry("Forward(256x32 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 32), 1, 100));

	Entries.push_back(entry("Forward(1024x1024 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 10, 10));
	Entries.push_back(entry("Forward(512x512 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 10, 10));
	Entries.push_back(entry("Forward(256x256 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 10, 10));
	Entries.push_back(entry("Forward(128x128 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 10, 10));
	Entries.push_back(entry("Forward(64x64 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 10, 10));
	Entries.push_back(entry("Forward(32x32 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 10, 10));
	Entries.push_back(entry("Forward(16x16 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 10, 10));
	Entries.push_back(entry("Forward(8x8 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 10, 10));
	Entries.push_back(entry("Forward(512x64 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 64), 10, 10));
	Entries.push_back(entry("Forward(512x32 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 32), 10, 10));
	Entries.push_back(entry("Forward(256x64 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 64), 10, 10));
	Entries.push_back(entry("Forward(256x32 - 10x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 32), 10, 10));

	Entries.push_back(entry("Forward(1024x1024 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 100, 1));
	Entries.push_back(entry("Forward(512x512 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 100, 1));
	Entries.push_back(entry("Forward(256x256 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 100, 1));
	Entries.push_back(entry("Forward(128x128 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 100, 1));
	Entries.push_back(entry("Forward(64x64 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 100, 1));
	Entries.push_back(entry("Forward(32x32 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 100, 1));
	Entries.push_back(entry("Forward(16x16 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 100, 1));
	Entries.push_back(entry("Forward(8x8 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 100, 1));
	Entries.push_back(entry("Forward(512x64 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 64), 100, 1));
	Entries.push_back(entry("Forward(512x32 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 32), 100, 1));
	Entries.push_back(entry("Forward(256x64 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 64), 100, 1));
	Entries.push_back(entry("Forward(256x32 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 32), 100, 1));

/*
	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 1, 1));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 1x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 1, 1));

	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 1, 10));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 1x viewport 10x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 1, 10));

	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 10, 1));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 10x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 10, 1));

	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 1x viewport 100x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 1, 100));

	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 100, 1));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 100x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 100, 1));

	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 1, 100));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 1x viewport 1000x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 1, 100));

	Entries.push_back(entry("ScreenspaceCoherence(1024x1024 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(1024, 1024), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(512x512 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(512, 512), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(256x256 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(256, 256), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(128x128 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(128, 128), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(64x64 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(64, 64), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(32x32 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(32, 32), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(16x16 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(16, 16), 1000, 1));
	Entries.push_back(entry("ScreenspaceCoherence(8x8 - 1000x viewport 1x tile)", glm::uvec2(1024, 1024), glm::uvec2(8, 8), 1000, 1));
*/
	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testScreenspaceCoherence Test(argc, argv, test::CORE, Entries[EntryIndex].WindowSize, Entries[EntryIndex].TileSize, Entries[EntryIndex].ViewportDrawCount, Entries[EntryIndex].TileDrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int compiler(int argc, char* argv[], csv & CSV)
{
	int Error(0);

	{
		testCompiler Test(argc, argv, test::CORE, testCompiler::MULTITHREADED);
		Error += Test();
		Test.log(CSV, "Multithreaded GLSL compiler");
	}

	{
		testCompiler Test(argc, argv, test::CORE, testCompiler::DUALTHREADED);
		Error += Test();
		Test.log(CSV, "Dualthreaded GLSL compiler");
	}

	{
		testCompiler Test(argc, argv, test::CORE, testCompiler::SINGLETHREADED);
		Error += Test();
		Test.log(CSV, "Singlethreaded GLSL compiler");
	}

	return Error;
}

int drawIndexing(int argc, char* argv[], csv & CSV)
{
	struct entry
	{
		entry(
			std::string const & String,
			testDrawIndexing::indexing const & Indexing,
			std::size_t const & DrawCount
		) :
			String(String),
			Indexing(Indexing),
			DrawCount(DrawCount)
		{}

		std::string const String;
		testDrawIndexing::indexing const Indexing;
		std::size_t const DrawCount;
	};

	int Error(0);

	std::vector<entry> Entries;

	Entries.push_back(entry("DrawIndexed(UNIFORM_INDEXING, 100000)", testDrawIndexing::UNIFORM_INDEXING, 100000));
	Entries.push_back(entry("DrawIndexed(ATTRIB_INDEXING, 100000)", testDrawIndexing::ATTRIB_INDEXING, 100000));
	Entries.push_back(entry("DrawIndexed(DIVISOR_INDEXING, 100000)", testDrawIndexing::DIVISOR_INDEXING, 100000));
	Entries.push_back(entry("DrawIndexed(DIVISOR_MULTI_INDEXING, 100000)", testDrawIndexing::DIVISOR_MULTI_INDEXING, 100000));
	Entries.push_back(entry("DrawIndexed(ID_INDEXING, 100000)", testDrawIndexing::ID_INDEXING, 100000));
	Entries.push_back(entry("DrawIndexed(NO_INDEXING, 100000)", testDrawIndexing::DRAW, 100000));

	for(std::size_t EntryIndex(0); EntryIndex < Entries.size(); ++EntryIndex)
	for(std::size_t TestIndex(0); TestIndex < TEST_DUPLICATE_COUNT; ++TestIndex)
	{
		testDrawIndexing Test(argc, argv, test::CORE, Entries[EntryIndex].Indexing, Entries[EntryIndex].DrawCount);
		Error += Test();
		Test.log(CSV, Entries[EntryIndex].String.c_str());
	}

	return Error;
}

int main(int argc, char* argv[])
{
	int Error(0);

	csv CSV;

	//Error += drawArrays(argc, argv, CSV);
	//Error += drawElements(argc, argv, CSV);
	//Error += drawArraysUniform(argc, argv, CSV);
	//Error += drawArraysVAOs(argc, argv, CSV);
	//Error += drawScreenspaceCoherence(argc, argv, CSV);
	//Error += compiler(argc, argv, CSV);
	Error += drawIndexing(argc, argv, CSV);

	CSV.print();
	CSV.save("../draws.csv");

	return Error;
}
