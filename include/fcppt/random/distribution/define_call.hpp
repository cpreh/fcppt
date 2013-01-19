//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL_HPP_INCLUDED


/**
\brief Defines the call operator for a distribution

\ingroup fcpptrandom

\param template_decl The template declaration, for example
<code>template<typename IntType></code>

\param template_pre The class name with full scope, for example
<code>mynamespace::myclass<IntType> </code>.
*/
#define FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL(\
	template_decl,\
	template_pre\
)\
template_decl \
template<\
	typename Engine\
>\
typename \
template_pre :: result_type \
template_pre :: operator()(\
	Engine &_engine\
)\
{\
	return \
		wrapped_(\
			_engine\
		);\
}

#endif
