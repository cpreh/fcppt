//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_EITHER_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/either/object_fwd.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

/**
\ingroup fcppteither
*/
template<
	typename Failure,
	typename Success
>
class object
{
public:
	typedef
	Failure
	failure;

	typedef
	Success
	success;

	static_assert(
		!std::is_same<
			Failure,
			Success
		>::value,
		"Success and Failure must be distinct"
	);

	explicit
	object(
		Success &&
	);

	explicit
	object(
		Success const &
	);

	explicit
	object(
		Failure &&
	);

	explicit
	object(
		Failure const &
	);

	bool
	has_success() const;

	bool
	has_failure() const;

	Success &
	get_success_unsafe();

	Success const &
	get_success_unsafe() const;

	Failure &
	get_failure_unsafe();

	Failure const &
	get_failure_unsafe() const;
private:
	typedef
	fcppt::variant::variadic<
		Failure,
		Success
	>
	variant_type;

	variant_type impl_;
};

}
}

#endif
