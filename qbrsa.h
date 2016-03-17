#include <stdio.h>
#include <wchar.h>

void look_up(int pnum, wchar_t* result)
{
 switch (pnum)
   {
    case 32:  swprintf (result, 2, L" "); break;
    case 33:  swprintf (result, 2, L"!"); break;
    case 39:  swprintf (result, 2, L"\'"); break;
    case 44:  swprintf (result, 2, L","); break;
    case 46:  swprintf (result, 2, L"."); break;
    case 48:  swprintf (result, 2, L"0"); break;
    case 49:  swprintf (result, 2, L"1"); break;
    case 50:  swprintf (result, 2, L"2"); break;
    case 51:  swprintf (result, 2, L"3"); break;
    case 52:  swprintf (result, 2, L"4"); break;
    case 53:  swprintf (result, 2, L"5"); break;
    case 54:  swprintf (result, 2, L"6"); break;
    case 55:  swprintf (result, 2, L"7"); break;
    case 56:  swprintf (result, 2, L"8"); break;
    case 57:  swprintf (result, 2, L"9"); break;
    case 58:  swprintf (result, 2, L":"); break;
    case 63:  swprintf (result, 2, L"?"); break;
    case 65:  swprintf (result, 2, L"A"); break;
    case 66:  swprintf (result, 2, L"B"); break;
    case 67:  swprintf (result, 2, L"C"); break;
    case 68:  swprintf (result, 2, L"D"); break;
    case 69:  swprintf (result, 2, L"E"); break;
    case 70:  swprintf (result, 2, L"F"); break;
    case 71:  swprintf (result, 2, L"G"); break;
    case 72:  swprintf (result, 2, L"H"); break;
    case 73:  swprintf (result, 2, L"I"); break;
    case 74:  swprintf (result, 2, L"J"); break;
    case 75:  swprintf (result, 2, L"K"); break;
    case 76:  swprintf (result, 2, L"L"); break;
    case 77:  swprintf (result, 2, L"M"); break;
    case 78:  swprintf (result, 2, L"N"); break;
    case 79:  swprintf (result, 2, L"O"); break;
    case 80:  swprintf (result, 2, L"P"); break;
    case 81:  swprintf (result, 2, L"Q"); break;
    case 82:  swprintf (result, 2, L"R"); break;
    case 83:  swprintf (result, 2, L"S"); break;
    case 84:  swprintf (result, 2, L"T"); break;
    case 85:  swprintf (result, 2, L"U"); break;
    case 86:  swprintf (result, 2, L"V"); break;
    case 87:  swprintf (result, 2, L"W"); break;
    case 88:  swprintf (result, 2, L"X"); break;
    case 89:  swprintf (result, 2, L"Y"); break;
    case 90:  swprintf (result, 2, L"Z"); break;
    case 97:  swprintf (result, 2, L"a"); break;
    case 98:  swprintf (result, 2, L"b"); break;
    case 99:  swprintf (result, 2, L"c"); break;
    case 100: swprintf (result, 2, L"d"); break;
    case 101: swprintf (result, 2, L"e"); break;
    case 102: swprintf (result, 2, L"f"); break;
    case 103: swprintf (result, 2, L"g"); break;
    case 104: swprintf (result, 2, L"h"); break;
    case 105: swprintf (result, 2, L"i"); break;
    case 106: swprintf (result, 2, L"j"); break;
    case 107: swprintf (result, 2, L"k"); break;
    case 108: swprintf (result, 2, L"l"); break;
    case 109: swprintf (result, 2, L"m"); break;
    case 110: swprintf (result, 2, L"n"); break;
    case 111: swprintf (result, 2, L"o"); break;
    case 112: swprintf (result, 2, L"p"); break;
    case 113: swprintf (result, 2, L"q"); break;
    case 114: swprintf (result, 2, L"r"); break;
    case 115: swprintf (result, 2, L"s"); break;
    case 116: swprintf (result, 2, L"t"); break;
    case 117: swprintf (result, 2, L"u"); break;
    case 118: swprintf (result, 2, L"v"); break;
    case 119: swprintf (result, 2, L"w"); break;
    case 120: swprintf (result, 2, L"x"); break;
    case 121: swprintf (result, 2, L"y"); break;
    case 163: swprintf (result, 2, L"£"); break;
    default:  swprintf (result, 2, L"€"); break;
	}
}
