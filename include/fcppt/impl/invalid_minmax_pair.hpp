//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IMPL_INVALID_MINMAX_PAIR_HPP_INCLUDED
#define FCPPT_IMPL_INVALID_MINMAX_PAIR_HPP_INCLUDED

inline
fcppt::invalid_minmax_pair::invalid_minmax_pair(
	fcppt::string const &_what
)
:
	fcppt::exception(
		_what
	)
{}

#endif
