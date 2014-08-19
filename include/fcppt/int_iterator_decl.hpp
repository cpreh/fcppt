//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INT_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_INT_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/int_iterator_fwd.hpp>
#include <fcppt/detail/int_iterator_base.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\ingroup fcpptint
*/
template<
	typename Int
>
class int_iterator
:
	public fcppt::detail::int_iterator_base<
		Int
	>
{
public:
	int_iterator();

	explicit
	int_iterator(
		Int
	);
private:
	friend class boost::iterator_core_access;

	void
	increment();

	bool
	equal(
		int_iterator
	) const;

	Int
	dereference() const;

	Int value_;
};

FCPPT_PP_POP_WARNING

}

#endif
