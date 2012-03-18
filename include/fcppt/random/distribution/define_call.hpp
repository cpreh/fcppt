//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_DEFINE_CALL_HPP_INCLUDED


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
