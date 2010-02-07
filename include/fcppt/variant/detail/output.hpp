//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_OUTPUT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_OUTPUT_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <ostream>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Stream
>
class output
{
	FCPPT_NONASSIGNABLE(output)
public:
	typedef Stream &result_type;

	explicit output(
		Stream &stream_
	)
	:
		stream_(stream_)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T const &t
	) const
	{
		return
			stream_ << t;
	}
private:
	Stream &stream_;
};

}
}
}

#endif
