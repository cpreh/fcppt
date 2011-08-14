//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED
#define FCPPT_ASSERT_EXCEPTION_HPP_INCLUDED

#include <fcppt/assert/information.hpp>
#include <fcppt/exception.hpp>

namespace fcppt
{
namespace assert_
{

class exception
:
	public fcppt::exception
{
public:
	explicit exception(
		assert_::information const &
	);

	assert_::information const &
	information() const;

	~exception() throw();
private:
	assert_::information information_;
};

}
}

#include <fcppt/assert/impl/exception.hpp>

#endif
