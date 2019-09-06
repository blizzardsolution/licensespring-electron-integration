# LicenseSpring SDK integration into Electron.js application

**Description**

This is a minimal Electron application based on the [Quick Start Guide](https://electronjs.org/docs/tutorial/quick-start) within the Electron documentation. This uses C++ SDK from [LicenseSpring](https://docs.licensespring.com/docs/c) to integrate License System into desktop application.

**Structure**

- `package.json` - Points to the app's main file and lists its details and dependencies.
- `binding.gyp` - Describes the configuration to build license sdk module, in a JSON-like format. This file gets placed in the root of your package, alongside package.json.
- `license-cpp-sdk` - Contains License Spring C++ SDK, espcially contents of [LicenseSpringCppSDKv4.4.7_VC140.zip](https://docs.licensespring.com/docs/c)
- `main.js` - Starts the app and creates a browser window to render HTML. This is the app's **main process**.
- `public/index.html` - A web page to render. This is the app's **renderer process**.

You can learn more about license sdk within [Getting Started guide](https://docs.licensespring.com/docs/getting-started).

## To Use

To clone and run this repository you'll need [Git](https://git-scm.com) and [Node.js](https://nodejs.org/en/download/) (which comes with [npm](http://npmjs.com)) installed on your computer. Also, you should install [node-gyp](https://github.com/nodejs/node-gyp) - Node.js native addon build tool.

From your command line:

```bash
# Clone this repository
git clone https://github.com/blizzardsolution/licensespring-electron-integration
# Go into the repository
cd licensespring-electron-integration
# Install dependencies
npm install
# Build Node addon
node-gyp configure build
# Run the app
npm run start
```

Note: If you're using Linux Bash for Windows, [see this guide](https://www.howtogeek.com/261575/how-to-run-graphical-linux-desktop-applications-from-windows-10s-bash-shell/) or use `node` from the command prompt.

## Resources for LicenseSpring SDK
- [LicenseSpring Documentation](https://docs.licensespring.com/) - All documents, descriptions and examples for LicenseSpring SDK

## Resources for Node Addon
- [Node addon](http://nodeaddons.com) - Node Addon documentation by example
- [node-gyp](https://github.com/nodejs/node-gyp) - Node.js native addon build tool

## Resources for Learning Electron

- [electronjs.org/docs](https://electronjs.org/docs) - all of Electron's documentation
- [electronjs.org/community#boilerplates](https://electronjs.org/community#boilerplates) - sample starter apps created by the community
- [electron/electron-quick-start](https://github.com/electron/electron-quick-start) - a very basic starter Electron app
- [electron/simple-samples](https://github.com/electron/simple-samples) - small applications with ideas for taking them further
- [electron/electron-api-demos](https://github.com/electron/electron-api-demos) - an Electron app that teaches you how to use Electron
- [hokein/electron-sample-apps](https://github.com/hokein/electron-sample-apps) - small demo apps for the various Electron APIs

## License

[CC0 1.0 (Public Domain)](LICENSE.md)
