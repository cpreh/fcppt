let pkgs = import <nixpkgs> {};
in pkgs.gcc8Stdenv.mkDerivation rec {
  pname = "fcppt";
  version = "3.2.2";

  src = pkgs.fetchFromGitHub {
    owner = "freundlich";
    repo = "fcppt";
    rev = version;
    sha256 = "09mah52m3lih2n0swpsh8qb72yzl4nixaq99xp7wxyxxprhf4bpa";
  };

  nativeBuildInputs = [ pkgs.cmake ];
  buildInputs = [ pkgs.boost pkgs.catch2 ];

  cmakeFlags = [ "-DENABLE_EXAMPLES=false" "-DENABLE_CATCH=true" "-DENABLE_TEST=true" "-DBrigand_INCLUDE_DIR=${pkgs.brigand}/include" ];

  enableParallelBuilding = true;

  meta = with pkgs.stdenv.lib; {
    description = "Freundlich's C++ toolkit";
    longDescription = ''
      Freundlich's C++ Toolkit (fcppt) is a collection of libraries focusing on
      improving general C++ code by providing better types, a strong focus on
      C++11 (non-conforming compilers are mostly not supported) and functional
      programming (which is both efficient and syntactically affordable in
      C++11).
    '';
    homepage = https://fcppt.org;
    license = licenses.boost;
    maintainers = with maintainers; [ pmiddend ];
    platforms = platforms.linux;
  };
}
