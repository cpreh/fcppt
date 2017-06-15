//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_TEMPORARY_OUTPUT_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_TEMPORARY_OUTPUT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/io/ostringstream.hpp>
#include <fcppt/log/detail/output_helper.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class temporary_output
{
	FCPPT_NONCOPYABLE(
		temporary_output
	);
public:
	FCPPT_LOG_DETAIL_SYMBOL
	temporary_output();

	FCPPT_LOG_DETAIL_SYMBOL
	temporary_output(
		temporary_output &&
	);

	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::string
	result() const;
private:
	// The unique_ptr should go when libstdc++ streams are movable
	fcppt::unique_ptr<
		fcppt::io::ostringstream
	> stream_;

	template<
		typename T
	>
	friend
	fcppt::log::detail::temporary_output
	operator<<(
		fcppt::log::detail::temporary_output &&,
		T const &
	);
};

template<
	typename T
>
fcppt::log::detail::temporary_output
operator<<(
	fcppt::log::detail::output_helper const &,
	T const &_arg
)
{
	return
		fcppt::log::detail::temporary_output()
		<< _arg;
}

template<
	typename T
>
fcppt::log::detail::temporary_output
operator<<(
	fcppt::log::detail::temporary_output &&_temp,
	T const &_arg
)
{
	*_temp.stream_ << _arg;

	return
		std::move(
			_temp
		);
}

}
}
}

#endif
