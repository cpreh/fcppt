//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_FOREACH_ENUMERATOR_HPP_INCLUDED
#define FCPPT_DETAIL_FOREACH_ENUMERATOR_HPP_INCLUDED


#define FCPPT_DETAIL_FOREACH_ENUMERATOR(\
	decl,\
	name\
) \
for(\
	decl;\
	name.running();\
	name.increment()\
)

#endif
