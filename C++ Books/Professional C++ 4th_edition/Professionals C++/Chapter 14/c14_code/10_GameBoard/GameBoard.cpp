#include "GameBoard.h"
#include <utility>
#include <stdexcept>
#include <new>

using namespace std;

GameBoard::GameBoard(size_t inWidth, size_t inHeight)
	: mWidth(inWidth), mHeight(inHeight)
{
	size_t i = 0;
	mCells = new GamePiece*[mWidth];

	try {
		for (i = 0; i < mWidth; i++) {
			mCells[i] = new GamePiece[mHeight];
		}
	}
	catch (...) {
		// We need to clean up any memory we already allocated,
		// because the destructor will never get called.
		// The upper bound of the for loop is the index of the last
		// element in the mCells array that we tried to allocate 
		// (the one that failed). All indices before that one store
		// pointers to allocated memory that must be freed.
		for (size_t j = 0; j < i; j++) {
			delete[] mCells[j];
		}
		delete[] mCells;
		mCells = nullptr;
		mWidth = mHeight = 0;

		// translate any exception to bad_alloc
		throw bad_alloc();
	}
}

GameBoard::GameBoard(const GameBoard& src)
	: GameBoard(src.mWidth, src.mHeight)
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

GameBoard::~GameBoard() noexcept
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
	// check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	// Copy-and-swap idiom
	GameBoard temp(rhs); // Do all the work in a temporary instance
	swap(*this, temp);   // Commit the work with only non-throwing operations
	return *this;
}

const GamePiece& GameBoard::at(size_t x, size_t y) const
{
	// Check for out of range arguments
	if (x >= mWidth)
		throw out_of_range("GameBoard::at: x-coordinate beyond width");
	if (y >= mHeight)
		throw out_of_range("GameBoard::at: y-coordinate beyond height");
	return mCells[x][y];
}

GamePiece& GameBoard::at(size_t x, size_t y)
{
	return const_cast<GamePiece&>(static_cast<const GameBoard&>(*this).at(x, y));
}
