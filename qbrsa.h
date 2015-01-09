char look_up(int pnum)
{
	char result;
	switch (pnum)
	{
		case 32:  result = ' '; break;
		case 33:  result = '!'; break;
		case 39:  result = '\''; break;
		case 44:  result = ','; break;
		case 46:  result = '.'; break;
		case 48:  result = '0'; break;
		case 49:  result = '1'; break;
		case 50:  result = '2'; break;
		case 51:  result = '3'; break;
		case 52:  result = '4'; break;
		case 53:  result = '5'; break;
		case 54:  result = '6'; break;
		case 55:  result = '7'; break;
		case 56:  result = '8'; break;
		case 57:  result = '9'; break;
		case 58:  result = ':'; break;
		case 63:  result = '?'; break;
		case 66:  result = 'B'; break;
		case 67:  result = 'C'; break;
		case 83:  result = 'S'; break;
		case 84:  result = 'T'; break;
		case 97:  result = 'a'; break;
		case 98:  result = 'b'; break;
		case 99:  result = 'c'; break;
		case 100: result = 'd'; break;
		case 101: result = 'e'; break;
		case 102: result = 'f'; break;
		case 103: result = 'g'; break;
		case 104: result = 'h'; break;
		case 105: result = 'i'; break;
		case 106: result = 'j'; break;
		case 107: result = 'k'; break;
		case 108: result = 'l'; break;
		case 109: result = 'm'; break;
		case 110: result = 'n'; break;
		case 111: result = 'o'; break;
		case 112: result = 'p'; break;
		case 113: result = 'q'; break;
		case 114: result = 'r'; break;
		case 115: result = 's'; break;
		case 116: result = 't'; break;
		case 117: result = 'u'; break;
		case 118: result = 'v'; break;
		case 119: result = 'w'; break;
		case 120: result = 'x'; break;
		case 121: result = 'y'; break;
		case 163: result = '£'; break;
		default: result='$';
	}
	return result;
}
