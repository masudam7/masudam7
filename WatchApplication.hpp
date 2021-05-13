/**
 * @file WatchApplication.hpp
 * @date 2020/05/13
 * @author kanazawama
 */

#pragma once

#include "Scheduler.hpp"
#include "InitializerConfig.hpp"

//masudam
//#define CHRONO_DEBUG

/**
 * @brief メインの時計アプリケーション。
 */
class WatchApplication{

	private:
		/** static class */
		WatchApplication();

	public:

		/**
		 * 時計のメインモード
		 */
		enum MainMode {
			TIME_MODE,		//!< 時刻通常
			TIME_FIX_MODE,	//!< 時刻修正
			HAND_FIX_MODE,	//!< 基準位置修正
//masudam
			CHRONO_MODE,	//!< クロノ

			POWER_BRAKE_MODE,	//!< パワーブレーク

			TEST_MODE,	//!< 検査モード

			UNKNOWN,		//!< 無効値
		};

	private:
		static MainMode mainMode;

	public:

		/**
		 * メインモードを変更する。
		 * @param newMode
		 */
		static void setMainMode(MainMode newMode){
			mainMode = newMode;
		}

	public:

		/**
		 * メインモードが一致するか確認する。
		 * @param mode
		 * @return 一致する場合 true
		 */
		inline static bool isMainMode(MainMode mode){
			return (mainMode == mode);
		}

	//==========================================================================================================
	// 初期化・終了処理
	//==========================================================================================================

	private:
		/**
		 * 初期化処理済みかどうかの状態。
		 */
		static InitializerTypedef::IsInitialized isInitialized;

	public:

		/**
		 * 初期化処理。依存モジュールから呼ばれる。
		 * @return 初期化済みかどうかを返す。
		 */
		static InitializerTypedef::IsInitialized initialize(void);

		/**
		 * 終了処理。 Initializer から呼ばれる。
		 */
		static void finalize(void);

	public:

		//TODO:モードに無関係な特殊なイベントのハンドラとか


};
