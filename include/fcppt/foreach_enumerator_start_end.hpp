//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FOREACH_ENUMERATOR_START_END_HPP_INCLUDED
#define FCPPT_FOREACH_ENUMERATOR_START_END_HPP_INCLUDED

#define FCPPT_FOREACH_ENUMERATOR_START_END(\
	name,\
	enum_,\
	start,\
	end\
)\
for(\
	enum_::type name = start;\
	name < end;\
	name = static_cast<enum_::type>(name + 1)\
)

#endif
