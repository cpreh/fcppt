//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_TEMPORARY_OUTPUT_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_TEMPORARY_OUTPUT_HPP_INCLUDED

#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/detail/output_helper.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/shared_ptr.hpp>
#include <fcppt/string.hpp>
#include <ostream>

namespace fcppt
{
namespace log
{
namespace detail
{

class temporary_output
{
public:
	FCPPT_SYMBOL temporary_output();

	FCPPT_SYMBOL string const
	result() const;
private:
	shared_ptr<
		io::ostringstream
	> os;

	template<
		typename T
	>
	friend temporary_output const
	operator<<(
		temporary_output const &,
		T const &
	);
};

template<
	typename T
>
temporary_output const
operator<<(
	output_helper const &,
	T const &t
)
{
	return temporary_output() << t;
}

template<
	typename T
>
temporary_output const
operator<<(
	temporary_output const &s,
	T const &t
)
{
	temporary_output n(s);
	*n.os << t;
	return n;
}

}
}
}

#endif
