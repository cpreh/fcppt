//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_ENUM_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/enum_iterator_fwd.hpp>
#include <fcppt/enum_size_type.hpp>
#include <fcppt/detail/enum_iterator_base.hpp>
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
\ingroup fcpptenum
*/
template<
	typename Enum
>
class enum_iterator
:
	public fcppt::detail::enum_iterator_base<
		Enum
	>
{
public:
	typedef
	typename
	fcppt::enum_size_type<
		Enum
	>::type
	size_type;

	enum_iterator();

	explicit
	enum_iterator(
		size_type
	);
private:
	friend class boost::iterator_core_access;

	void
	increment();

	bool
	equal(
		enum_iterator
	) const;

	Enum
	dereference() const;

	size_type value_;
};

FCPPT_PP_POP_WARNING

}

#endif
