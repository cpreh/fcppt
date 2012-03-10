//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/nonassignable.hpp>
#include <fcppt/noncopyable.hpp>

namespace
{

//! [noncopyable]
class test_noncopyable
{
	FCPPT_NONCOPYABLE(
		test_noncopyable
	);
public:
	test_noncopyable()
	:
		ptr_(new int(42))
	{
	}

	~test_noncopyable()
	{
		delete ptr_;
	}
private:
	int *ptr_;
};
//! [noncopyable]

//! [nonassignable]

// The following is not assignable because it has a reference and a constant
class test_nonassignable
{
	FCPPT_NONASSIGNABLE(
		test_nonassignable
	);
public:
	test_nonassignable(
		int &_some_ref,
		float const _some_float
	)
	:
		some_ref_(
			_some_ref
		),
		float_constant_(
			_some_float
		)
	{
	}
private:
	int &some_ref_;

	float const float_constant_;
};
//! [nonassignable]

}

int
main()
{
}
