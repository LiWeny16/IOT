import React, { useEffect, useState,useRef } from "react";
import Process from "../Components/Process.tsx";
import Statisic from "../Components/Statistic.tsx";
import Calendar from "../Components/Calendar.tsx";
import settings from "../Global.jsx"
import axios from "axios";
// import NaviTop from "../Components/NaviTop.tsx";
function App() {
  const [dataAll, setdataAll] = useState(["/","/"]); // 定义state:count
  const [loadState,setLoadState] = useState(true)
 
  // setTimeout(()=>{
  //   getData().then((e) => {
  //     let data = e.data;
  //     data = data.replace(/(\r)|(\?)|(\n)/g, "");
  //     data = data.split(",");
  //     console.log(data);
  //     setdataAll(data);
  //     setLoadState(false);
  //     console.log(loadState);
  //   })
  // },1000)
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
      <div className="FLEX COL">
        <div className="FLEX ROW">
          <div className="MARGIN" id="indexBoxLeft">
            <div>
              <Process dataAll={[dataAll,loadState]}></Process>
            </div>
            <div>
              <Statisic dataAll={[dataAll,loadState]}></Statisic>
            </div>
          </div>
          {/* <div className="MARGIN">
            <Calendar />
          </div> */}
        </div>
      </div>
    </>
  );
}
export default App;

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
