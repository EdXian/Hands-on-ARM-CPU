/********************************************************************
Copyright 2010-2017 K.C. Wang, <kwang@eecs.wsu.edu>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/

int g;                  // global int g

int main()
{
  int a,b,c,d,e,f;      // locals of main()
  g = 12;
  
  a=1;
  b=2;
  c=3;
  d=4;
  e=5;
  f=6;

  g = sum(a,b,c,d,e,f); // call sum() with 6 parameters

  while(1);
}

  
