import { Switch } from "antd";
import axios from "axios";

// @ts-ignore
import settings from "../../src/Global.jsx"
// const onChange = (checked: boolean) => {
//   console.log(`switch to ${checked}`);
//   getData("LED").then(() => {
//     console.log("doit");
//   });
// };

function Switcher(id: any) {
  return (
    <>
      <Switch
        defaultChecked
        onChange={() => {
          controlEN(id.id)
          console.log(id.id);
        }}
      />
    </>
  );
}
export default Switcher;

function controlEN(num: any): any {
  return new Promise((resolve) => {
    let axiosConfig = {
      method: "GET",
      url: `${settings.domain}/switch?a=1&b=${num}`,
    };
    axios(axiosConfig)
      .then((res) => {
        resolve(res);
      })
      .catch((error) => {
        console.log(error);
      });
  });
}
