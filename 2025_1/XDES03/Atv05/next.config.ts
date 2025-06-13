import type { NextConfig } from "next";

const nextConfig: NextConfig = {
  images: {
    remotePatterns: [
      {
        protocol: "https",
        hostname: "lumiere-a.akamaihd.net",
        pathname: "**",
      },
    ],
  },
};

export default nextConfig;
