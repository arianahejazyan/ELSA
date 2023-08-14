#pragma once
#include "vector"

// Offsets
enum {Up=14, UpRight=15, Right=1, DownRight=-13, Down=-14, DownLeft=-15, Left=-1, UpLeft=+13, UpUp=28, RightRight=2, DownDown=-28, LeftLeft=-2};

// Pieces
enum {invalid=-1, empty=0, Pawn=1, Knight=2, Bishop=3, Rook=4, Queen=5, King=6};

// Players
enum {none=0, Red=1, Blue=2, Yellow=3, Green=4};

// Special moves
enum {doublePush=0, Castle=1, enpassant=2, Promotion=3};

// Squares
enum {a1,  b1,  c1,  d1,  e1,  f1,  g1,  h1,  i1,  j1,  k1,  l1,  m1,  n1,
      a2,  b2,  c2,  d2,  e2,  f2,  g2,  h2,  i2,  j2,  k2,  l2,  m2,  n2,
      a3,  b3,  c3,  d3,  e3,  f3,  g3,  h3,  i3,  j3,  k3,  l3,  m3,  n3,
      a4,  b4,  c4,  d4,  e4,  f4,  g4,  h4,  i4,  j4,  k4,  l4,  m4,  n4,
      a5,  b5,  c5,  d5,  e5,  f5,  g5,  h5,  i5,  j5,  k5,  l5,  m5,  n5,
      a6,  b6,  c6,  d6,  e6,  f6,  g6,  h6,  i6,  j6,  k6,  l6,  m6,  n6,
      a7,  b7,  c7,  d7,  e7,  f7,  g7,  h7,  i7,  j7,  k7,  l7,  m7,  n7,
      a8,  b8,  c8,  d8,  e8,  f8,  g8,  h8,  i8,  j8,  k8,  l8,  m8,  n8,
      a9,  b9,  c9,  d9,  e9,  f9,  g9,  h9,  i9,  j9,  k9,  l9,  m9,  n9,
      a10, b10, c10, d10, e10, f10, g10, h10, i10, j10, k10, l10, m10, n10,
      a11, b11, c11, d11, e11, f11, g11, h11, i11, j11, k11, l11, m11, n11,
      a12, b12, c12, d12, e12, f12, g12, h12, i12, j12, k12, l12, m12, n12,
      a13, b13, c13, d13, e13, f13, g13, h13, i13, j13, k13, l13, m13, n13,
      a14, b14, c14, d14, e14, f14, g14, h14, i14, j14, k14, l14, m14, n14};

// It is used to update castling rights
int castle_rights[196] = {
    0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b11111111, 0b11111111, 0b11111111, 0b11111100, 0b11111111, 0b11111111, 0b11111101, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b01111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11110011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b00111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11110111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,
    0b11111111, 0b11111111, 0b11111111, 0b11011111, 0b11111111, 0b11111111, 0b11001111, 0b11111111, 0b11111111, 0b11111111, 0b11101111, 0b11111111, 0b11111111, 0b11111111,
};

const struct CastleInfo 
{   
    //  Rights[Player][Side]
    int Rights[4][2] = {
        {0b00000001, 0b00000010},
        {0b00000100, 0b00001000},
        {0b00010000, 0b00100000},
        {0b01000000, 0b10000000}
    };

    //  UpdateRooks[Player][Side][from-to]
    int UpdateRooks[4][2][2] = {
        {{8,   10},  {7,   4}},
        {{70,  42},  {98,  140}},
        {{185, 183}, {187, 190}},
        {{124, 153}, {111, 55}},
    };

    //  PassingSquares[Player][Index]
    int PassingSquares[5][5] = {
        {0  , 0  , 0  , 0  , 0  },
        {4  , 5  , 6  , 8  , 9  },
        {56 , 70 , 98 , 112, 126},
        {139, 125, 111, 83 , 69 },
        {191, 190, 189, 187, 186},
    };
};

struct Position
{
    int board[196];
    int colors[196];
    int royals[4];
    int enpassant[196];
    int castle;
    int turn;
};

struct MoveList
{
    void add_pawn_moves(std::vector<int> moves)
    {

    }

    void add_knight_moves(std::vector<int> moves)
    {

    }
};

# define rank(square) (square / 14)
# define file(square) (square % 14)
# define team(player) (player % 2)
# define isInvalidSquare(r, f) ((r > 10 && f > 10) || (r < 3 && f > 10) || (r < 3 && f < 3) || (r > 10 && f < 3))
# define get_source(move) (move & 0xff)
# define get_target(move) ((move >> 8 ) & 0xff)
# define get_flag(move) (move >> 16)

// Init relevant squares

std::vector<std::vector<int>> init_king_relevant_squares();
std::vector<std::vector<int>> init_knight_relevant_squares();
std::vector<std::vector<int>> init_pawn_relevant_squares();

std::vector<std::vector<int>> init_queen_relevant_squares();
std::vector<std::vector<int>> init_rook_relevant_squares();
std::vector<int>** init_bishop_relevant_squares();

// Init piece attacks

std::vector<std::vector<int>> init_king_attacks();
std::vector<std::vector<int>> init_knight_attacks();
std::vector<std::vector<int>> init_pawn_attacks();

std::vector<std::vector<int>> init_queen_attacks();
std::vector<std::vector<int>> init_rook_attacks();
std::vector<std::vector<int>> init_bishop_attacks();

// Piece relevant squares

std::vector<int> KnightRelevantSquares[196];
std::vector<int> KingRelevantSquares[196];

std::vector<int> BishopRelevantSquares[196][4];
std::vector<int> RookRelevantSquares[196][4];
std::vector<int> QueenRelevantSquares[196][4];

// Piece moves

std::vector<std::vector<int>> PawnMoves[196][4];
std::vector<std::vector<int>> KnightMoves[196];
std::vector<std::vector<int>> BishopMoves[196];
std::vector<std::vector<int>> RookMoves[196];
std::vector<std::vector<int>> QueenMoves[196];
std::vector<std::vector<int>> KingMoves[196];