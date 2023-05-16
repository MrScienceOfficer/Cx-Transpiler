
//anonomys namespace "char"

typedef anon_width_t char;
typedef anon_Filepath char*;
typedef anon_String anon_width_t*;

struct anon__Text {
	anon_width_t *Data;
	anon_width_t *Position;
	int len;
};

anon_Text *anon_Text__anon_Filepath(anon_Filepath path) {
	anon_Text *ret =(anon_Text*)malloc(sizeof(anon_Text));
	
	FILE *f = fopen(path, "r");
   ret->Position = NULL;

   if (!f) return NULL; 
   fseek(f, 0, SEEK_END);
   ret->Length = ftell(f);
   rewind(f);
   ret->Data = (anon_width_t*)malloc((sizeof(anon_width_t))*ret->len);
   fread(ret->Data, (sizeof(anon_width_t)), ret->len, f);
   fclose(f);

	return ret;
}

anon_Text *anon_Text__anon_width_t(anon_width_t *text) {
   anon_Text *ret = (anon_Text*)malloc(sizeof(anon_Text));
	
	ret->Data = text;
	while(++text) ++ret->len;
   
	return ret;
}

anon_Text *anon_Text__anon_width_t(anon_width_t *text, int len) {
	anon_Text *ret = (anon_Text*)malloc(sizeof(anon_Text));

	ret->Data = text;
	ret->len = len;

	return ret;
}

bool anon_Text__is_next__anon_String(anon_Text *this, anon_String match) {
	char *c = this->Position;
	while (isspace(*c)) ++c;
	int p = 0;
	while (match[p]) {
		if (str[p] == c[p]) ++p;
			else return 0;
		}
	return 1;
}


