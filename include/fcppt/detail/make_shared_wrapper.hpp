//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_MAKE_SHARED_WRAPPER_HPP_INCLUDED
#define FCPPT_DETAIL_MAKE_SHARED_WRAPPER_HPP_INCLUDED

#include <fcppt/detail/make_shared_wrapper_fwd.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

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
	typedef boost::shared_ptr<
		T
	> ptr_type;

	explicit make_shared_wrapper(
		ptr_type const _ptr
	)
	:
		ptr_(_ptr)
	{
	}

	ptr_type const
	get() const
	{
		return ptr_;
	}
private:
	ptr_type ptr_;
};

}
}

#endif
