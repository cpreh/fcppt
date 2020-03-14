//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/preprocessor/disable_clang_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_CLANG_WARNING(-Wunused-member-function)
//! [noncopyable]
class test_noncopyable
{
	FCPPT_NONCOPYABLE(
		test_noncopyable
	);
public:
	test_noncopyable()
	:
		ptr_(new int(1))
	{
	}

	test_noncopyable(
		test_noncopyable &&_other
	)
	noexcept
	:
		ptr_{_other.ptr_}
	{
		_other.ptr_ = nullptr;
	}

	test_noncopyable &
	operator=(
		test_noncopyable &&_other
	)
	noexcept
	{
		if(&_other == this)
		{
			return *this;
		}

		ptr_ = _other.ptr_;
		_other.ptr_ = nullptr;

		return *this;
	}

	~test_noncopyable()
	noexcept
	{
		delete ptr_;
	}
private:
	int *ptr_;
};
//! [noncopyable]
FCPPT_PP_POP_WARNING

}

int
main()
{
	test_noncopyable test1{};
}
