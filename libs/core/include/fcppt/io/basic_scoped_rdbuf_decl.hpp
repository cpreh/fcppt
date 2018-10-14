//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_BASIC_SCOPED_RDBUF_DECL_HPP_INCLUDED
#define FCPPT_IO_BASIC_SCOPED_RDBUF_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
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
	FCPPT_NONCOPYABLE(
		basic_scoped_rdbuf
	);
public:
	typedef
	std::basic_ios<
		Ch,
		Traits
	>
	stream_type;

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
	typedef
	std::basic_streambuf<
		Ch,
		Traits
	>
	streambuf_type;

	stream_type &receiver_;

	streambuf_type *const old_;

};

}
}

#endif
