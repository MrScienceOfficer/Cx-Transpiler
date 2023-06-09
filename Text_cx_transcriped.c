// Cx Text.h
// Tom Bishop
// This software is licensed under the Human License.
//
//      HUMAN LICENSE
// This software is free to use, modify, extend, publish and sell
// without restriction in public; meaning to say your software must be
// available to purchase for all humans equaly, reasonably and publicly.
// Or your software can be shared privately in groups up to 12 persons,
// so long as it retains this copyright and license. Usage of this software
// by non-human entities is strictly regulated.
//
// Usage of this software by non-human entities requires expensive licenses,
// paid to the author(s) of this software, details of this can be found at
// www@com.  All Humans must promise to comply with these stipulations
// to use or be inspired by this software, failure to do is not advised.
//
// "Non-human entities" is defined per the Human License as groups
// of persons larger then 12 persons with the ability to privately share
// this software, even if said ability were to be forbidden or unprecedented.
//
// "Your software" is defined per the Human License as any code, software or
// program that either includes, is inspired by, or is generated by any
// Human Licensed code including compiling or linking with,
// dynamically or statically, to any Human Licensed code, written or generated.


typedef Filepath char*;
typedef String char*;

typedef width_t char;
struct Text {
	width_t *Data;
	width_t *Position;
	int len;
};

Text *Text__Filepath
(Filepath path) {
	Text *ret =(Text*)malloc(sizeof(Text));

	FILE *f = fopen(path, "r");
   ret->Position = NULL;

   if (!f) return NULL; 
   fseek(f, 0, SEEK_END);
   ret->Length = ftell(f);
   rewind(f);
   ret->Data = (width_t*)malloc((sizeof(width_t))*ret->len);
   fread(ret->Data, (sizeof(width_t)), ret->len, f);
   fclose(f);

	return ret;
}

Text *Text__width_t
(width_t *text) {
   Text *ret = (Text*)malloc(sizeof(Text));
	
	ret->Data = text;
	while(++text) ++ret->len;
   
	return ret;
}

Text *Text__width_t
(width_t *text, int len) {
	Text *ret = (Text*)malloc(sizeof(Text));

	ret->Data = text;
	ret->len = len;

	return ret;
}

bool Text__is_next__String
(Text *this, String match) {
	char *c = this->Position;
	while (isspace(*c)) ++c;
	int p = 0;
	while (match[p]) {
		if (str[p] == c[p]) ++p;
			else return 0;
		}
	return 1;
}

bool Text__is_next__char
(Text *this, char match) {
	char *c = this->Position;
	while (isspace(*c)) ++c;
	return *c == match;
}

void Text__move_to__char
(Text *this, char match) {
	width_t *c = this->Position;
	do {
	if (*c == match)
      ;
	} while (++c);
}

void Text__move_to__String
(Text *this, String match) {
      char *c  = this->Position;
      int p = 0;
      while (match[p]) {
         if (match[p] == c[p]) ++p;
         else {
            if (c[p] && c[p] != EOF)
               return moveTo(c+p+1, match);
         }
      }
      return this->Position = c+p;
   }

void Text__move_to_paired__width_t__width_t
(Text *this, width_t start, width_t end) {
	char *c = this->Position;
	if (*c == start) {
      int open = 1;
      while (open) {
         if (*(++c) == end)
            --open;
         else if (*c == start)
            ++open;
      }
		return this->Position = c;
	}
	return NULL;
}

char *Text__select_first_of__width_t
(Text *this, width_t *match_set)> {
      width_t *chars = match_set;
      do {
         int i = 0;
      do {
         if (*c == *chars)
            return match_set[i];
      } while (++i && *(++chars));
      } while (*(++c));
      this->C = c;
   }

char *Text__get_current_word__
() {
  // @char{} word { x, y } = { @->!Position };
	char *word = malloc(sizeof(char) * 2);
 	word[0] = word[1] = this->Position;
   while (isspace(word[0])) ++word[0];
   while (isalnum(word[0])) --word[0];
   word[1] = word[0]
   while (isalnum(word[1])) ++word[1];
   return word;
}


/*this is problematic because
 * traits are not real and in my
 * imagination this shouldnt be done
 * butt obviously then there is no
 * way to take a base pointer to any derived type
 * and would need to alawys use void*
 * which sounds bad
 *
 * It seems most reasonable to generate
 * all the traits as needed.
 *
 *	Which brings us back to the original issue
 *	of potential cyclical type depedencies where
 *	Array__Symbol for example is also a part
 *	of Symbol.
 *
 *	This example seems trivial, however more 
 *	complicated composition structures
 *	seem much harder to resolve.
 * */

struct Symbol;

struct Array__Symbol {
	struct Symbol *elems;
	unsigned len;
};

struct Symbol {
	struct Symbol *previous;
	struct Symbol *next;
	struct Array__Symbol kids;

	char type;
	Text text;
};

/*this shouldnt exist maybe..
  ... Traits never allocate any data
  but they do need to 
  initialize their members.
 */
void Symbol__init
(Symbol *this, Text *text) {
	this->previous = NULL;
	this->next = NULL;
	this->kids.elems = NULL;
	this->kids.len = 0;
	this->text = text;
	this->type = -1;
}


struct C_Text {
	Symbol _0_this;
};

void C_Text__init__Text
(C_Text *this, Text *text) {
	Symbol__init(this, text);
	this->type = 0;//@Symbol.Type.C_TEXT;
}

C_Text *C_Text__alloc__Text
(Text *text) {
	C_Text *this = (C_Text*)malloc(sizeof(C_Text));
	C_Text__init__Text(this, text);
	return this;
}


struct Cx_Text {
	Symbol _0_this;
};

void Cx_Text__init
(Cx_Text *this) {
	this->type = 1;//@Symbol.Type.CX_TEXT
}

Cx_Text *Cx_Text__alloc__
(Text *text) {
	Cx_Text *this = (Cx_Text*)malloc(sizeof(C_Text));
	Symbol__init(this, text);
	CX_Text__init(this);
	return this;
}


struct Cx_Trait {
	Symbol _0_this;
	char *name;
	char operator;
	char *expression;
};

char Cx_Trait__Operator[] = "++=**=//=";

Cx_Trait *Cx_Trait__init__Text
(Cx_Trait *this, Text *text) {
	this->type = 1;//@Symbol.Type.CX_TRAIT
	this->text = text;
}



