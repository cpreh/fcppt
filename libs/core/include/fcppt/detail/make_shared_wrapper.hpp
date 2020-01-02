//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MAKE_SHARED_WRAPPER_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_SHARED_WRAPPER_HPP_INCLUDED

#include <fcppt/detail/make_shared_wrapper_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename T
>
class make_shared_wrapper
{
public:
	typedef
	std::shared_ptr<
		T
	>
	ptr_type;

	explicit
	make_shared_wrapper(
		ptr_type &&_ptr
	)
	:
		ptr_(
			std::move(
				_ptr
			)
		)
	{
	}

	ptr_type
	release()
	{
		return
			std::move(
				ptr_
			);
	}
private:
	ptr_type ptr_;
};

}
}

#endif
