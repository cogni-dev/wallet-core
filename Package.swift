// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "WalletCore",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "WalletCore", targets: ["WalletCore"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "WalletCore",
            url: "https://github.com/trustwallet/wallet-core/releases/download/4.0.40/WalletCore.xcframework.zip",
            checksum: "449604b386cc18d953ab90554fb7c2b2e1a22e493a9a9e6f5922dfdda174391a"
        )
    ]
)
