//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECURSIVE_DECL_HPP_INCLUDED
#define FCPPT_RECURSIVE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/recursive_fwd.hpp>
#include <fcppt/unique_ptr_decl.hpp>


namespace fcppt
{

/**
\brief Turns an incomplete type into a complete one, allowing recursion.

\ingroup fcpptvarious

Unfortunately, C++ makes no guarantees that incomplete types
can be used as a template parameter of a container like
std::vector. For example, the following might or might not work:
\code
struct X { std::vector<X> x; };
\endcode
The recursive class uses a unique pointer internally which allows
its type to be incomplete. We can therefore write
\code
struct X { std::vector<fcppt::recursive<X>> x; };
\endcode
*/
template<
	typename Type
>
class recursive
{
	FCPPT_NONCOPYABLE(
		recursive
	);
public:
	explicit
	recursive(
		Type const &
	);

	explicit
	recursive(
		Type &&
	);

	recursive(
		recursive &&
	) noexcept;

	recursive &
	operator=(
		recursive &&
	) noexcept;

	~recursive();

	Type &
	get();

	Type const &
	get() const;
private:
	fcppt::unique_ptr<
		Type
	> impl_;
};

}

#endif
