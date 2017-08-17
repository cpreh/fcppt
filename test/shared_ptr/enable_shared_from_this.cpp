//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enable_shared_from_this.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/shared_ptr_output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

class test_class;

typedef
fcppt::shared_ptr<
	test_class
>
test_shared_ptr;

typedef
fcppt::shared_ptr<
	test_class const
>
const_test_shared_ptr;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

class test_class
:
public
	fcppt::enable_shared_from_this<
		test_class
	>
{
public:
	test_shared_ptr
	get()
	{
		return
			this->fcppt_shared_from_this();
	}

	const_test_shared_ptr
	get() const
	{
		return
			this->fcppt_shared_from_this();
	}
};

FCPPT_PP_POP_WARNING

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	enable_shared_from_this
)
{
FCPPT_PP_POP_WARNING

	test_shared_ptr const ptr{
		fcppt::make_shared_ptr<
			test_class
		>()
	};

	test_shared_ptr const ptr2{
		ptr->get()
	};

	BOOST_CHECK_EQUAL(
		ptr,
		ptr2
	);

	const_test_shared_ptr const ptr3{
		ptr2
	};

	const_test_shared_ptr const ptr4{
		ptr3->get()
	};

	BOOST_CHECK_EQUAL(
		ptr3,
		ptr4
	);
}
