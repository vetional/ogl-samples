#ifndef TEST_DRAW_ARRAYS_INCLUDED
#define TEST_DRAW_ARRAYS_INCLUDED

#include "test.hpp"

class testDrawArrays : public test
{
public:
	enum drawType
	{
		INSTANCED,
		MULTI_DISCARD,
		MULTI_DRAW,
		DRAW_PACKED,
		DRAW_PARAMS
	};

	enum vertexDataType
	{
		SEPARATED_VERTEX_DATA,
		SHARED_VERTEX_DATA
	};

private:
	enum buffer
	{
		BUFFER_FRAME,
		BUFFER_ARRAY,
		BUFFER_INDIRECT,
		BUFFER_MAX
	};

public:
	testDrawArrays(
		int argc, char* argv[], profile Profile,
		drawType const DrawType, vertexDataType const VertexDataType, std::size_t const DrawCount);
	virtual ~testDrawArrays();

	virtual void render();

	bool initProgram();
	bool initBuffer();
	bool initVertexArray();

private:
	drawType const DrawType;
	vertexDataType const VertexDataType;
	std::size_t const DrawCount;
	GLuint VertexArrayName;
	GLuint PipelineName;
	GLuint ProgramName;
	std::array<GLuint, BUFFER_MAX> BufferName;
};

#endif//TEST_DRAW_ARRAYS_INCLUDED