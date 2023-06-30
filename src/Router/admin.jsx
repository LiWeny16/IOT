import React, { useEffect, useState } from "react";
import Switcher from "../Components/Switcher.tsx";
import RedShowCard from "../Components/RedShowCard.tsx";
import Calendar from "../Components/Calendar.tsx";
import axios from "axios";
import settings from "../Global.jsx";
export default function IndexApp() {
  const [dataAll, setdataAll] = useState(["?", "?"]); // 定义state:count
  const [loadState, setLoadState] = useState(true);
  useEffect(() => {
    const t = setInterval(() => {
      getData().then((e) => {
        let data = e.data;
        data = data.replace(/(\r)|(\?)/g, "");
        data = data.split(",");
        console.log(data);
        setdataAll(data);
        setLoadState(false);
        console.log(loadState);
      });
    }, 2000);
    return () => {
      clearTimeout(t);
    };
  }, []);

  return (
    <>
      <div className="FLEX ROW">
        {/* switch-1 */}
        <div className="FLEX COL MARGIN " id="switch-1">
          <div className="MARGIN">
            <p className="P3">总开关</p>
            <Switcher id={0} />
          </div>
          <div className="MARGIN">
            <p className="P3">温度开关</p>
            <Switcher id={6} />
          </div>
          <div className="MARGIN">
            <p className="P3">湿度开关</p>
            <Switcher id={7} />
          </div>
          <div className="MARGIN">
            <p className="P3">光强开关</p>
            <Switcher id={5} />
          </div>
          <div className="MARGIN">
            <p className="P3">人红外使能</p>
            <Switcher id={8} />
          </div>
        </div>
        {/* switch-2 */}
        <div className="FLEX COL MARGIN " id="switch-2">
          <div className="MARGIN">
            <p className="P3">灯光1</p>
            <Switcher id={1} />
          </div>
          <div className="MARGIN">
            <p className="P3">灯光2</p>
            <Switcher id={2} />
          </div>
          <div className="MARGIN">
            <p className="P3">灯光3</p>
            <Switcher id={3} />
          </div>
          <div className="MARGIN">
            <p className="P3">灯光4</p>
            <Switcher id={4} />
          </div>
          <div className="MARGIN">
            <p className="P3">灯光5</p>
            <Switcher id={"LED"} />
          </div>
        </div>
        <div className="FLEX MARGIN ROW">
          <div id="humanSensor">
            <RedShowCard  dataAll={[dataAll,loadState]} />
          </div>
          <div id="Calendar">
            <Calendar  dataAll={[dataAll,loadState]} />
          </div>
        </div>
      </div>
    </>
  );
}

function getData() {
  return new Promise((resolve) => {
    let axiosConfig;
    axiosConfig = {
      method: "get",
      url: `${settings.domain}/getdata`,
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
