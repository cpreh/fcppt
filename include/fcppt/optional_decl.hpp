//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/empty_optional_tag_fwd.hpp>
#include <fcppt/optional_fwd.hpp>
#include <fcppt/safe_bool.hpp>
#include <fcppt/detail/optional_base_decl.hpp>


namespace fcppt
{

template<
	typename T
>
class optional
:
	detail::optional_base<
		T
	>
{
	FCPPT_SAFE_BOOL(
		optional
	)

	typedef detail::optional_base<
		T
	> base;
public:
	typedef T value_type;

	typedef typename base::reference reference;

	typedef typename base::const_reference const_reference;

	typedef typename base::pointer pointer;

	typedef typename base::const_pointer const_pointer;

	optional();

	// intentionally not explicit
	optional(
		empty_optional_tag const &
	);

	// intentionally not explicit
	optional(
		const_reference
	);

	optional(
		optional const &
	);

	optional &
	operator=(
		optional const &
	);

	optional &
	operator=(
		const_reference
	);

	~optional();

	reference
	operator*();

	const_reference
	operator*() const;

	pointer
	operator->();

	const_pointer
	operator->() const;

	void
	reset();

	bool
	has_value() const;
private:
	bool
	boolean_test() const;
};

}

#endif
