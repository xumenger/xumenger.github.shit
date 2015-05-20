#include <assert.h>
#include <stdarg.h>
#include <iostream>
#include <stdexcept>

using namespace std;

void error(char const *fmt, ...) {
   assert(fmt);
   va_list p;
   va_start(p, fmt);
   for (char const *s = fmt; *s; ++s)
      if (*s!='%')
         std::cerr.put(*s);
      else
         switch (*(++s)) {
         case '%': std::cerr.put('%'); break;
         case 's': std::cerr << va_arg(p, char const*); break;
         case 'c': std::cerr << va_arg(p, char); break;
         case 'd': std::cerr << va_arg(p, int); break;
         default: throw std::domain_error(std::string ("panic"));
         }
   va_end(p);
}

int main() {
   error("A string \"%s\", a single character \'%c\', an integer %d\n"
         "and a percent-symbol \'%%\'.\n",
         "Hello World", '$', 12345);
   system("pause"); 
   return 0;
}
