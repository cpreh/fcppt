//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_BASE_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_BASE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>
#include <fcppt/options/base_fwd.hpp>
#include <fcppt/options/has_parameter_set.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/is_object.hpp>


namespace fcppt
{
namespace options
{

/**
\brief The base class for parsers with a given result type.

\ingroup fcpptoptions

This class serves as a base class for a concrete parser using \a Result as its
result type. Hiding a concrete parser implementation is not necessary, but it
can reduce compile times, and it hides the concrete (permuted) result type.

\tparam Result The result type of the parser. Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Result
>
class base
{
	FCPPT_NONCOPYABLE(
		base
	);

	static_assert(
		fcppt::record::is_object<
			Result
		>::value,
		"Result must be an fcppt::record::object"
	);
protected:
	base();
public:
	virtual
	~base() = 0;

	typedef
	Result
	result_type;

	virtual
	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::state &
	) const = 0;

	virtual
	fcppt::options::has_parameter_set
	parameters() const = 0;

	virtual
	fcppt::string
	usage() const = 0;
};

}
}

#endif
