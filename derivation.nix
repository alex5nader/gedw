{ stdenv
, meson, ninja, pkg-config, fd
, glfw, glew, xorg }:

stdenv.mkDerivation rec {
  pname = "gedw";
  version = "0.1";

  src = ./gedw;

  nativeBuildInputs = [ meson ninja pkg-config fd ];
  buildInputs = [ glfw glew xorg.libX11 ];
}
