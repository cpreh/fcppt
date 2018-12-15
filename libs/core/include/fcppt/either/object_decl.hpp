//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_EITHER_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_EITHER_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/either/object_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace either
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

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

FCPPT_PP_POP_WARNING

}
}

#endif
