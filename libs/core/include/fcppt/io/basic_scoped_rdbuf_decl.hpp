//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_BASIC_SCOPED_RDBUF_DECL_HPP_INCLUDED
#define FCPPT_IO_BASIC_SCOPED_RDBUF_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/io/basic_scoped_rdbuf_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{

/**
\brief Gives a streambuf from one stream to another, restoring the original
state in the destructor.

\ingroup fcpptio
*/
template<
	typename Ch,
	typename Traits
>
class basic_scoped_rdbuf
{
	FCPPT_NONMOVABLE(
		basic_scoped_rdbuf
	);
public:
	using
	stream_type
	=
	std::basic_ios<
		Ch,
		Traits
	>;

	/**
	\brief Gives a streambuf from one stream to another

	\param source The stream whose streambuf to take
	\param receiver The stream that will receive the streambuf
	*/
	basic_scoped_rdbuf(
		stream_type &source,
		stream_type &receiver
	);

	~basic_scoped_rdbuf();
private:
	using
	streambuf_type
	=
	std::basic_streambuf<
		Ch,
		Traits
	>;

	stream_type &receiver_;

	streambuf_type *const old_;

};

}
}

#endif
