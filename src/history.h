/*
Firenzina is a UCI chess playing engine by Kranium (Norman Schmidt)
Firenzina is based on Ippolit source code: http://ippolit.wikispaces.com/
authors: Yakov Petrovich Golyadkin, Igor Igorovich Igoronov,
and Roberto Pescatore copyright: (C) 2009 Yakov Petrovich Golyadkin
date: 92th and 93rd year from Revolution
owners: PUBLICDOMAIN (workers)
dedication: To Vladimir Ilyich
"This Russian chess ship is a truly glorious achievement of the
 October Revolution and Decembrists movement!"

Firenzina is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Firenzina is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see http://www.gnu.org/licenses/.
*/

#define Shift 8
#define HistoryGood(move, depth)                                             \
 { int sv = HistoryValue (Position , move);                                  \
   HistoryValue (Position, move) = sv + (((0xff00 - sv) * depth) >> Shift); \
   if (move != Position->Dyn->killer1)                                        \
     { Position->Dyn->killer2 = Position->Dyn->killer1;                       \
       Position->Dyn->killer1 = move; } }
#define HistoryBad(move, depth)                                              \
  { int sv = HistoryValue (Position, move);                                  \
    if (Pos0->Value > value - HistoryThreshold)                                             \
      HistoryValue (Position, move) = sv - ((sv * depth) >> Shift); }
#define HistoryBad1(move, depth)                                             \
  { int sv = HistoryValue (Position, move);                                  \
    if (Pos0->Value > Alpha - HistoryThreshold)                                             \
      HistoryValue (Position, move) = sv - ((sv * depth) >> Shift); }

