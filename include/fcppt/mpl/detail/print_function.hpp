//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_PRINT_FUNCTION_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_PRINT_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/mpl/detail/print_one.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

class print_function
{
	FCPPT_NONASSIGNABLE(
		print_function
	);
public:
	explicit
	print_function(
		fcppt::io::ostream &_stream
	)
	:
		stream_(
			_stream
		)
	{
	}

	typedef void result_type;

	template<
		typename Type
	>
	result_type
	operator()() const
	{
		fcppt::mpl::detail::print_one<
			Type
		>(
			stream_
		);

		stream_
			<< FCPPT_TEXT(',');
	}
private:
	fcppt::io::ostream &stream_;
};

}
}
}

#endif
