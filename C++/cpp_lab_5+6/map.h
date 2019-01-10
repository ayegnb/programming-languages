#ifndef MAP_INCLUDED
#define MAP_INCLUDED 1

#include <map>

struct case_insensitive_cmp;

std::map< std::string, unsigned int, case_insensitive_cmp > frequencytable( const std::vector< std::string > & text );

std::ostream& operator << ( std::ostream& stream,
  const std::map< std::string, unsigned int, case_insensitive_cmp > & freq );

#endif
