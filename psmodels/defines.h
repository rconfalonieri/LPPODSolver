// Copyright 1998 by Patrik Simons
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston,
// MA 02111-1307, USA.
//
// Patrik.Simons@hut.fi
#ifndef DEFINES_H
#define DEFINES_H

typedef enum {
  ENDRULE,
  BASICRULE,
  CONSTRAINTRULE,
  CHOICERULE,
  GENERATERULE,
  WEIGHTRULE,
  OPTIMIZERULE
} RuleType;

#ifdef USEDOUBLE
typedef double Weight;
#define WEIGHT_MAX DBL_MAX
#define WEIGHT_MIN -DBL_MAX
#else
typedef unsigned long Weight;
#define WEIGHT_MAX ULONG_MAX
#define WEIGHT_MIN 0
#endif

#endif
